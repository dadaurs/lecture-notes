#include <iostream>
using namespace std;
class Magicien{
	public:
		void setnum(int num){
			num_assistant = num;
		}
		void add(){
			num_assistant+=115;
		}
		void annonce(){
			cout<<"l age est"<<num_assistant<<endl;
		}
	private:
		int num_assistant;
};
class Assistant{
	public:
		void get_argent(int dollar){
			if (dollar>=0 and dollar<=99){
				argent=dollar;

			}
		}
		void get_age(int a){
			age=a;
		}
		int set_magie(){
			nb_magique= 50*( 2*age+5 )+argent-365;
			cout<< nb_magique<<endl;
			return nb_magique;
		}

		
	private:
		int nb_magique;
		int argent;
		int age;
};
class Spectateur{
	public:
		void get_age(){
			cout<< "cekoitonage?"<<endl;
			cin>> age;
		}
		void get_argent(){
			cout<<"kombiendethunesfrr?"<<endl;
			cin>> argent;
		}
		int set_age(){
			return age;
		}
		int set_argent(){
			return argent;
		}
	private:
		int age;
		int argent;
};

int main(){
Spectateur s;
Assistant a;
Magicien m;
s.get_age();
s.get_argent();
a.get_age(s.set_age());
a.get_argent(s.set_argent());
m.setnum(a.set_magie());
m.add();
m.annonce();


return 0;
}
