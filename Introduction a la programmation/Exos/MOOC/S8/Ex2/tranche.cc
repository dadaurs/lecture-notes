#include <iostream>
#include <vector>
using namespace std;
typedef size_t Position;
typedef  vector<int> Sequence;
struct SousSequence{
size_t debut;
size_t fin;
int somme;
};
SousSequence tranchemax1(Sequence seq){
int sum=0;
SousSequence sseq= {1,1,seq[0]};
for(size_t i=0;i<seq.size();++i){
sum=0;
	for(size_t j=0;j<i;++j){
		for(size_t k=i;k<j;++k){
			sum=sum + seq[k];
		}
	if(sum> sseq.somme){
		sseq= {i,j,sum};
	}
	}

}
return sseq;
}
SousSequence tranchemax2(Sequence seq){
int sum=0;
SousSequence sseq= {1,1,seq[0]};
for(size_t i=0;i<seq.size();++i){
	sum=0;
	for(size_t j=0;j<i;++j){
		sum+= seq[j];
	if(sum> sseq.somme){
		sseq= {i,j,sum};
	}
	}

}
return sseq;
}
SousSequence tranchemax3(Sequence seq){
int sum=0;
SousSequence sseq= {1,1,seq[0]};
size_t deb=1;
for(size_t fin=0;fin<seq.size();++fin){
	sum+=seq[fin];
	if(sum>sseq.somme)
		sseq={deb,fin,sum};
	if(sum<=0){
		deb=fin+1;
		sum=0;
	}

	}

return sseq;
}


int main(){
Sequence seq = {11,13,-4,3,-26,7,-13,25,-2,17,5,-8,1};



return 0;
}































