#include<iostream>
using namespace std;



class A{
    public:
        double x;
        double y;
        A(double b,double c):x(b),y(c){}
        // A(int a){
        //     cout<<"hahahahah"<<endl;
        //     x = a;
        //     y=0.0;
        // }
        A(const A& p){x = p.x*2;}
        void get(){
            
            cout<<x<<endl;
        }
        
        

};

// A & func(){
//     A a(1);
//     A &x = a;
//     return x;
// }


int main(){
    A q(11,12);
    q.get();
    q = {10,2};
    q.get();
    // A r(13,31);
    // r.get();
    // r = 14;
    // r.get();
    // A r;
    // r = p;
    // r.get();
    // cout<<p.x;
    return 0;
}
