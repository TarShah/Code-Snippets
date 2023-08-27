const int nax = ...;
vector<bool> isp(nax,true);
vector<int> mindv(nax);
void calc(){
	isp[0] = false;
	isp[1] = false;
	for(int i=2;i<nax;i++){
		if(isp[i]){
			mindv[i] = i;
			for(int j=2*i;j<nax;j+=i){
				isp[j] = false;
				if(mindv[j] == 0) mindv[j] = i;
			}
		}
	}
	return;
}
