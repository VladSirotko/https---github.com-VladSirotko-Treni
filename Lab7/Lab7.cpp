#include <iostream>
#include <algorithm>
#include <vector>
#include <cstdlib>

using namespace std;

class Predicate{
public:
	Predicate(int value):value(value){}
	bool operator()(int a){
		if(a>value){
			return true;
		}
		else{
			return false;
		}
	}
private:
	int value;
};
void show(int i){
	cout<<i<<"~~";
}
int main(){
	vector <int> v;
	int r=0;
	for(int i=0;i<20;++i){
		v.push_back(rand()% -199-99);
	}
	sort(v.begin(),v.end());
	for(auto it=v.begin(),end=v.end();it!=end;++it){
	cout<<*it<<" ";
	}
	cout<<endl;
	cout<<"Number of elements more than "<<r<<" : "<<count_if(v.begin(),v.end(),Predicate(r))<<endl;  //15-6

	cout<<endl;
	int n=-50,m=50;

	auto new_end=remove_if(v.begin(), v.end(),[n,m](int a){return (a>n && a<m);});
	v.erase(new_end,v.end());
	for(int i=0;i<v.size();++i){
	cout<<v[i]<<" ";
	}
	cout<<endl;
	cout<<"Max: "<<*max_element(v.begin(), v.end())<<"   "<<"Min: "<<*min_element(v.begin(), v.end())<<endl;
	return 0;
}
