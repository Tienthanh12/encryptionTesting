#include<iostream>
#include <bitset>
#include<string>

using namespace std;


bool rtaps[100] = {1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 1, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 1, 0, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 1, 1, 1};
bool comp0[100] = {0 /*comp0[0]=X*/, 0, 0, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 1, 0, 1, 0, 1, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 0, 0, 1, 1, 1, 1, 0, 1, 0, 0, 1, 1, 1, 1, 0, 1, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0 /*comp0[100]=X*/};
bool comp1[100] = {0 /*comp1[0]=X*/, 1, 0, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 1, 0, 1, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 0, 1, 0, 0, 0, 0, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 1, 1, 0, 1, 1, 0, 0, 1, 0, 0, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0 /*comp1[100]=X*/};
bool fb0[100] = {0, 0, 0, 0, 1, 0, 1, 1, 1, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 0, 0, 1, 0, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 0, 0, 0, 0, 1, 1, 1, 1, 0, 0, 1, 0, 1, 1, 0, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 1, 1, 1, 0, 0, 1, 1, 1, 1, 0, 0, 1, 1, 0, 1, 0, 0, 0, 1, 1, 0, 0, 1, 0, 0, 0};
bool fb1[100] = {0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 0, 0, 0, 1, 0, 0, 1, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 0, 1, 0, 1, 1, 1, 1, 0, 0, 0, 1, 0, 0, 0, 1, 0, 1, 1, 0, 1, 1, 0, 1, 1, 0, 0, 0, 0, 0, 0, 1, 0, 0, 1, 1, 1, 1, 1, 0, 1, 1, 1, 0, 1, 1, 1, 1, 1, 0, 1, 0, 1, 1, 0, 1, 0, 0, 1, 0, 0, 1, 1, 1, 1, 0, 0, 0};

void clock_r(bool (&x)[100], bool ctrl_bit, bool input_bit){
    bool fb_bit = x[99]^input_bit;
    bool r_prev[100];
    for (int i = 0; i<100; i++) r_prev[i]=x[i];
    for (int i = 1; i<100; i++) x[i]=r_prev[i-1]; 
    x[0]=0;
    for (int i = 0; i<100; i++)
    if (rtaps[i]) x[i]=x[i]^fb_bit;
    if (ctrl_bit) for (int i = 0; i<100; i++) x[i]=x[i]^r_prev[i];
}

void clock_s(bool (&x)[100], bool ctrl_bit, bool input_bit){
    bool fb_bit = x[99]^input_bit;
    bool s_prev[100];
    for (int i = 0; i<100; i++) s_prev[i]=x[i];
    for (int i = 1; i<99; i++) x[i]=s_prev[i-1]^((s_prev[i]^comp0[i])&(s_prev[i+1]^comp1[i]));
    x[0]=0; x[99]=s_prev[98];
    if (!ctrl_bit) for (int i = 0; i<100; i++) x[i]=x[i]^(fb_bit&fb0[i]);
    else for (int i = 0; i<100; i++) x[i]=x[i]^(fb_bit&fb1[i]);
}

void clock_kg(bool (&x)[100], bool (&y)[100], bool mix, bool input_bit){
    bool ctrl_r = y[34]^x[67];
    bool ctrl_s = y[67]^x[33];
    bool input_r, input_s;
    if (mix) input_r=input_bit^y[50];
    else input_r=input_bit;
    input_s=input_bit;
    clock_r(x,ctrl_r,input_r);
    clock_s(y,ctrl_s,input_s);
}

void init(bool (&x)[100], bool (&y)[100], bool z[80], bool t[], int n){
    for (int i = 0; i<100; i++) {x[i]=0; y[i]=0;}
    for (int i = 0; i<n; i++) clock_kg(x,y,1,t[i]);
    for (int i = 0; i<80; i++) clock_kg(x,y,1,z[i]);
    for (int i = 0; i<100; i++) clock_kg(x,y,1,0);
}


int gcd(int a, int b){
    if (b==0) return a;
    else return gcd(b, a%b);
}

void asciiToBitArray(const std::string& asciiString, bool bitArray[]) {
    int index = 0;
    
    // Convert each character to its binary representation
    for (char c : asciiString) {
        // Convert character to ASCII code
        int asciiValue = static_cast<int>(c);
        
        // Convert ASCII code to binary
        bitset<7> binary(asciiValue); // ASCII uses 7 bits
        
        // Append each bit to the bit array
        for (int i = 0; i < 7; ++i) {
            bitArray[index++] = binary[i];
        }
    }
}


int main(void)
{
    string input;
    cout<< "enter the message: ";
    getline(cin, input);

    const int size =input.length() * 7;
    bool iv[80];
    bool k[80];
    bool r[100];
    bool s[100];
    bool plaintext[size];
    bool cyphertext[size];
    bool keystream[size];
    
    asciiToBitArray(input, plaintext);


    for (bool& bit : iv) {
        bit = rand() % 2; // Randomize the data
    }
    for (bool& bit : k) {
        bit = rand() % 2; // Randomize the data
    }

    cout<< "Key: ";
    for(int i =0; i< 80; i++)
    {
        cout<< k[i];
    }
    cout<<endl;
    cout<<"iv: ";
    for(int i =0; i< 80; i++)
    {
        cout<< iv[i];
    }
    init(r,s,k,iv,80);

    for (int i = 0; i< size; i++) 
    {
        keystream[i]=r[0]^s[0];
        cyphertext[i]=plaintext[i]^keystream[i];
        clock_kg(r,s,0,0);
    }
    cout<< endl;
    cout<<"cyphertext: ";
    for(int i =0; i< size; i++)
    {
        cout<< cyphertext[i];
    };
    cout<<endl;

}
    