#include <iostream>

using namespace std;
static int count= NULL;

struct test {
     string sontak;
     
};
class Power 
{
public:
Power()
{
   
    cout << "Haven't object create: " << count << endl;
     count++;
}
~Power()
{
    cout << "Object destroyed" << count << endl;
    count--;
}
};

int main() {
cout << "Perbedaan class dan struct \n";
Power p,p1,p2,p3,p4;

return 0;
}