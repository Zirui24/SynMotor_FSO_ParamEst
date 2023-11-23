function RTW_rtwnameSIDMap() {
	this.rtwnameHashMap = new Array();
	this.sidHashMap = new Array();
	this.rtwnameHashMap["<Root>"] = {sid: "MATLAB0"};
	this.sidHashMap["MATLAB0"] = {rtwname: "<Root>"};
	this.rtwnameHashMap["<S1>"] = {sid: "MultiParamEst:1"};
	this.sidHashMap["MultiParamEst:1"] = {rtwname: "<S1>"};
	this.rtwnameHashMap["<S1>:1"] = {sid: "MultiParamEst:1:1"};
	this.sidHashMap["MultiParamEst:1:1"] = {rtwname: "<S1>:1"};
	this.getSID = function(rtwname) { return this.rtwnameHashMap[rtwname];}
	this.getRtwname = function(sid) { return this.sidHashMap[sid];}
}
RTW_rtwnameSIDMap.instance = new RTW_rtwnameSIDMap();
