module random_encounters {
  import random;
  int last_ship;
  float significant_distance;
  float detection_distance;
  bool curmode;//are we in battle mode (true) or cruise mode (false)
  bool lastmode;//were we in battle mode (true) or cruise mode(false)
  void init(float sigdis, float detectiondis){
    detection_distance = detectiondis;
    significant_distance = sigdis;
    last_ship=0;
    curmode=false;
    lastmode=false;
  };
  void launch_near (object un) {
    
  }
  bool isSignificant(object un) {
    object unit_fgid = _unit.getFgID(un);
    if (_unit.isPlanet (un) ||
	_unit.isJumppoint(un) ||
	_string.equal (unit_fgid,"Nebula") ||
	_string.equal (unit_fgid,"Base") ||
	_string.equal (unit_fgid,"Asteroid")) {
      _string.delete(fgid);
      return true;
    }
    _string.delete(fgid);
    return false;
  };
  bool atLeastNInsignificantUnitsNear (object unit, int n) {
    int num_ships=0;
    int count=0;
    object un = _unit.getUnit (count);
    while (!_std.isNull(object)) {
      if (_unit.getDistance(unit,un)<detection_distance) {
	if (!isSignificant(un)) {
	  num_ships=num_ships+1;
	  if (num_ships>=n)
	    return true;
	}
      }
      count=count+1;
      object = _unit.getUnit(count);
    }
    return false;
  };
 
  object decideMode() {
    object un= _unit.getUnit (last_ship);
    if (_std.isNull (un)) {
      cur_mode=false;
      last_ship=0;
    }else {
      object player_unit=_unit.getPlayer();
      if (!std.isNull(player_unit)) {
	if (_unit.getDistance(un,player_unit)<significant_distance&&isSignificant(un)) {
	  cur_mode=true;
	  last_ship=0;
	  return un;
	}	  
      }
      last_ship=last_ship+1;
    }
    _std.setNull(un);
    return un;
  };
  void Loop() {
    object un = decideMode ();
    if (cur_mode!=last_mode) {
      cur_mode=last_mode;//processed this event; don't process again if in critical zone
      if (!std.isNull(un)) {
	if (!atLeastNInsignificantUnitsNear (unit,2)) {
	  //determine whether to launch more ships next to significant thing based on ships in that range  
	  launch_near (unit);
	} 
      }
    }
  };
  void InitSystem () {
    last_ship=0;
    Loop();
    while (last_ship!=0) {
      Loop();//goes through all ships in system to make sure enemies are there when arrive
    }
  };

}

