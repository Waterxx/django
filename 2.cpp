#include <bits/stdc++.h>

using namespace std;

int GCD(int a,int b)
{
    if (a == 0 || b == 0)
       return 0;
 
    if (a == b)
        return a;
 
    if (a > b)
        return GCD(a-b, b);
    return GCD(a, b-a);
}


int maximumGcdAndSum(vector <int> A, vector <int> B, int n) {

    	set<int> a;
    	set<int> b;
    	for(int i=0;i<n;i++) a.insert(A[i]);
    	for(int i=0;i<n;i++) b.insert(B[i]);
    	int x=a.size();
    	int y=b.size();

    int mark1[5*100000]={0};
    int mark2[5*100000]={0};

    for(set<int>::iterator i=a.begin(); i!=a.end(); i++){
	int e1 = *i;
        for(int j=1;j*j<= e1;j++){
            if(e1%j==0){
                mark1[j]++;
                mark1[e1/j]++;
            }
        }
    }

    for(set<int>::iterator i=b.begin(); i!=b.end(); i++){
	int e2 = *i;
        for(int j=1;j*j<= e2;j++){
            if(e2%j==0){
                mark2[j]++;
                mark2[e2/j]++;
            }
        }
    }
    
    vector<int> s1;
    vector<int> s2;
    for(set<int>::iterator i=a.begin(); i!=a.end(); i++){
	int e1 = *i;
        if(mark1[e1]==1) s1.push_back(e1);
    }
    for(set<int>::iterator i=b.begin(); i!=b.end(); i++){
	int e2 = *i;
        if(mark2[e2]==1) s2.push_back(e2);
    }
    
    
    int gcd=0, sum=0;
    for(int i=0;i<s1.size();i++){
        for(int j=0;j<s2.size();j++){
            if(GCD(s1[i],s2[j]) >= gcd){
                gcd = GCD(s1[i], s2[j]);
                sum = s1[i]+s2[j];
            }
        }
    }
    return sum;
}

int main() {
    int n;
    cin >> n;
    vector<int> A(n);
    for(int A_i = 0; A_i < n; A_i++){
       cin >> A[A_i];
    }
    vector<int> B(n);
    for(int B_i = 0; B_i < n; B_i++){
       cin >> B[B_i];
    }
    int res = maximumGcdAndSum(A, B, n);
    cout << res << endl;
    return 0;
}

