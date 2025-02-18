#include <iostream>

using namespace std;

int main(int argc,char *argv[]){
float sum = 0;
int num_count = 0;
for (int i = 1;i<argc;i++){
    sum += atoi(argv[i]);
    num_count++;
}
if (num_count > 0){
    cout<<"---------------------------------\n";
    cout << "Average of "<< num_count <<" numbers = "<< sum/num_count <<endl;
    cout<<"---------------------------------";}
 else{cout <<"Please input numbers to find average.";}

return 0;
}
