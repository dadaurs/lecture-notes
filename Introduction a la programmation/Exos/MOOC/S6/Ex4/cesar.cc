#include <iostream>
#include <string>
using namespace std;

char decale(char c, char debut, int dec){
	while(dec<0){
		dec+=26;
	}

return debut + (((c - debut) + dec) % 26);

}
char code(char c, int d){
	if(c > 'a' && c<'z'){
	return decale(c,'a',d);
	}else if(c > 'A' && c<'Z'){
	return decale(c,'A',d);
	}
	return c;


}
string code(string s,int  d){
	string enc;
	for(int i=0;i<s.size();i++){
		enc+=code(s[i],d);
	}
return enc;

}
string decode(string s,int  d){
	string enc;
	for(int i=0;i<s.size();i++){
		enc+=code(s[i],-d);
	}
return enc;

}




int main(){

return 0;
}
