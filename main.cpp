//QANCHA KUN YASHAGANIMIZNI HISOBLASH DASTURI
#include <iostream>
using namespace std;

class Inson{
private:
    string ismi;
    int yil;
    int oy;
    int kun;
public:
    void setTaminla(string ismi, int yil, int oy, int kun){
        this->ismi=ismi;
        this->yil=yil;
        this->oy=oy;
        this->kun=kun;
    }

    string getIsm(){
        return ismi;
    }

    int getKun(int hozirgi_yil,int hozirgi_oy, int hozirgi_kun){
        int s=0;
        for(int i=yil; i<=hozirgi_yil; i++){
            if(i!=yil and i!=hozirgi_yil){                               // kabisa to'liq yil
                if(i%400==0 or i%4==0 and i%100!=0)
                s+=366;
                else
                    s+=365;                                           // kabisa bo'lmagan to'liq yil
            }
            else
            for(int j=1; j<=12; j++){
                if(j==4 or j==6 or j==9 or j==11){                          // 30 kunlik oy
                    if(i==yil and j==oy)
                        s+=(31-kun);
                    else
                    if(i==yil and j>oy or i==hozirgi_yil and j<hozirgi_oy)
                        s+=30;
                    if(i==hozirgi_yil and j==hozirgi_oy)
                        s+=(hozirgi_kun-1);
                }
                else
                if(j==2){                                           // fevral
                    if(i%400==0 or i%4==0 and i%100!=0){
                        if(i==yil and j==oy)
                            s+=(30-kun);
                        else
                        if(i==yil and j>oy or i==hozirgi_yil and j<hozirgi_oy)
                            s+=29;
                        if(i==hozirgi_yil and j==hozirgi_oy)
                            s+=(hozirgi_kun-1);
                    }
                    else
                    {
                        if(i==yil and j==oy)
                            s+=(29-kun);
                        else
                        if(i==yil and j>oy or i==hozirgi_yil and j<hozirgi_oy)
                            s+=28;
                        if(i==hozirgi_yil and j==hozirgi_oy)
                            s+=(hozirgi_kun-1);
                    }
                }
                else
                if(j==1 or j==3 or j==5 or j==7 or j==8 or j==10 or j==12){          // 31 kunlik oy
                    if(i==yil and j==oy)
                        s+=(32-kun);
                    else
                    if(i==yil and j>oy or i==hozirgi_yil and j<hozirgi_oy)
                        s+=31;
                    if(i==hozirgi_yil and j==hozirgi_oy)
                        s+=(hozirgi_kun-1);
                }
            }
        }
        return s;
    }
};

int main()
{
    string S;
    int a,b,c,d,e,f;
    cout<<"        Iltimos ismingiz yozing: ";  cin>>S;
    cout<<"\n        Tug'ilgan yil / oy / kun ningizni  kiriting  "<<endl<<endl;
    cout<<" ::::  ---  Tug'ilgan yilingiz  --- ::::  "; cin>>a;
    cout<<" ::::  ---  Tug'ilgan oyingiz  --- ::::  "; cin>>b;
    cout<<" ::::  ---  Tug'ilgan kuningiz  --- ::::  "; cin>>c;
    cout<<endl<<"       Hozirgi yil / oy / kun ni kiriting  "<<endl<<endl;
    cout<<" ::::  ---  Hozirgi yil  --- ::::  "; cin>>d;
    cout<<" ::::  ---  Hozirgi oy  --- ::::  "; cin>>e;
    cout<<" ::::  ---  Hozirgi kun  --- ::::  "; cin>>f;
    Inson A;
    A.setTaminla(S,a, b, c);
    cout<<"\n               "<<A.getIsm()<<" siz hozirgacha  "<< A.getKun(d,e,f)<<"  kun yashadingiz "<<endl;
}