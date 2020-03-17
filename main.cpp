#include <iostream>

using namespace std;
class Vector
{
    int *V;
    int len;
public:
///constructor initializare
    Vector()
    {
        len=0;
    }
///constructor pentru initializarea cu un numar dat pe toate componentele
    Vector(int x, int L)
    {
        V=new int[L];
        len=L;
        for(int i=0; i<len; i++)
            V[i]=x;
    }
///constructor de copiere
    Vector(Vector &a)
    {
        V=new int[a.len];
        len=a.len;
        for(int i=0; i<len; i++)
            V[i]=a.V[i];
    }
///destructor
    ~Vector()
    {
        len=0;
        delete[]V;
    }

///metoda-operator public de atribuire =;
    Vector operator = (const Vector& W)
    {
        if(this != &W)
        {
            if(len)
                delete[] V;
            len = W.len;
            V = new int[len];
            for(int i=0; i<W.len; i++)
                V[i] = W.V[i];
        }
        return *this;
    }
///metoda publica pentru reactualizarea numarului de componente si initializarea componentelor cuun numar dat
    void Reactualizare(int x, int L)
    {
        V=new int[L];
        len=L;
        for(int i=0; i<len; i++)
            V[i]=x;
    }
///metoda publica pentru calculul sumei tuturor elementelor vectorului;
    int Suma()
    {
        int s=0;
        for(int i=0; i<len; i++)
            s=s+V[i];
        return s;
    }
///metoda publica pentru găsirea maximului și a pozitiei lui;
    void Maxim()
    {
        int maxx=0,poz=-1;
        for(int i=0; i<len; i++)
            if(V[i]>maxx)
            {
                maxx=V[i];
                poz=i;
            }
        cout<<maxx<<" "<<poz<<endl;
    }
///metoda publica pentru sortarea crescătoare a vectorului;
    void Sortare()
    {
        int ok;
        do
        {
            int ok=0;
            for(int i=0; i<len-1; i++)
                for(int j=i+1; j<len; j++)
                    if(V[i]>V[j])
                    {
                        swap(V[i],V[j]);
                        ok=1;
                    }
        }
        while(ok);
    }

///supraincarcarea >>
    friend istream & operator >> (istream &os, Vector& W)
    {
        cout<<"len= ";
        os>>W.len;
        W.V=new int[W.len];
        for(int i=0; i<W.len; i++)
            os>>W.V[i];
        return os;
    }

///supraincarcarea <<
    friend ostream & operator << (ostream &os,Vector& W)
    {
        cout<<"Vector=";
        for(int i=0; i<W.len; i++)
            os<<W.V[i]<<" ";
        return os;
    }
///citire/afisare/memorare n obiecte
    void Citire(int n)
    {
        Vector *W;
        W=new Vector[n];
        for(int i=1; i<=n; i++)
            cin>>W[i];

        for(int i=1; i<=n; i++)
            cout<<W[i]<<endl;
    }
///produsul scalar a doi vectori de aceeasi lungime, implementat prin supraincarcarea operatorului *.
    Vector operator*(const Vector W)
    {
        Vector aux;
        if(len!=W.len)
            cout<<"nu exista";
        else
        {
            aux.len=W.len;
            aux.V=new int[W.len];
            for(int i=0; i<W.len; i++)
                aux.V[i]=V[i]*W.V[i];
            return aux;
        }
    }
};
int main()
{
    Vector V,W,X;
    cin>>V;
    cin>>W;
    X=V*W;
    cout<<X;




    return 0;
}
