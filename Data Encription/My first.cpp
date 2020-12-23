#include<bits/stdc++.h>
using namespace std;
char encode[129];
char decode[129];
void DecodeEncode(){
  encode['c'] = '!';
  encode['e'] = '@';
  encode['z'] = '#';
  encode['k'] = '$';
  encode['l'] = '%';
  encode['u'] = '^';
  encode['x'] = '&';
  encode['i'] = '*';
  encode['a'] = '(';
  encode['g'] = ')';
  encode['y'] = '-';
  encode['s'] = '_';
  encode['q'] = '+';
  encode['r'] = '=';
  encode['d'] = '|';
  encode['o'] = '"';
  encode['w'] = ']';
  encode['j'] = '?';
  encode['m'] = '/';
  encode['t'] = ';';
  encode['v'] = '>';
  encode['b'] = '<';
  encode['n'] = ',';
  encode['f'] = ':';
  encode['h'] = '.';
  encode['p'] = '`';
  encode[' '] = '[';

  encode['C'] = '!';
  encode['E'] = '@';
  encode['Z'] = '#';
  encode['K'] = '$';
  encode['L'] = '%';
  encode['U'] = '^';
  encode['X'] = '&';
  encode['I'] = '*';
  encode['A'] = '(';
  encode['G'] = ')';
  encode['Y'] = '-';
  encode['S'] = '_';
  encode['Q'] = '+';
  encode['R'] = '=';
  encode['D'] = '|';
  encode['O'] = '"';
  encode['W'] = ']';
  encode['J'] = '?';
  encode['M'] = '/';
  encode['T'] = ';';
  encode['V'] = '>';
  encode['B'] = '<';
  encode['N'] = ',';
  encode['F'] = ':';
  encode['H'] = '.';
  encode['P'] = '`';

  encode['0'] = 'x';
  encode['1'] = 'c';
  encode['2'] = 'f';
  encode['3'] = 'd';
  encode['4'] = 'g';
  encode['5'] = 's';
  encode['6'] = 'j';
  encode['7'] = 'a';
  encode['8'] = 'l';
  encode['9'] = 'q';

  decode['!'] = 'c';
  decode['@'] = 'e';
  decode['#'] = 'z';
  decode['$'] = 'k';
  decode['%'] = 'l';
  decode['^'] = 'u';
  decode['&'] = 'x';
  decode['*'] = 'i';
  decode['('] = 'a';
  decode[')'] = 'g';
  decode['-'] = 'y';
  decode['_'] = 's';
  decode['+'] = 'q';
  decode['='] = 'r';
  decode['|'] = 'd';
  decode['"'] = 'o';
  decode[']'] = 'w';
  decode['?'] = 'j';
  decode['/'] = 'm';
  decode[';'] = 't';
  decode['>'] = 'v';
  decode['<'] = 'b';
  decode[','] = 'n';
  decode[':'] = 'f';
  decode['.'] = 'h';
  decode['`'] = 'p';
  decode['['] = ' ';

  decode['x'] = '0';
  decode['c'] = '1';
  decode['f'] = '2';
  decode['d'] = '3';
  decode['g'] = '4';
  decode['s'] = '5';
  decode['j'] = '6';
  decode['a'] = '7';
  decode['l'] = '8';
  decode['q'] = '9';
}
int main(){
    DecodeEncode();

    ofstream out("in.txt",out.out);
    ifstream in("in.txt",in.in);
    string first_name,middle_name,last_name,age;

    getline(cin,first_name);
    getline(cin,middle_name);
    getline(cin,last_name);
    cin>>age;
    int i=0;
    while (first_name[i]!='\0')out<<encode[first_name[i++]];
    out<<" ";
    i=0;
    while (middle_name[i]!='\0')out<<encode[middle_name[i++]];
    out<<" ";
    i=0;
    while (last_name[i]!='\0')out<<encode[last_name[i++]];
    out<<" ";
    i=0;
    while (age[i]!='\0')out<<encode[age[i++]];
    out<<"\n";
    out.close();
    
    string a,b,c,d;
    in>>a>>b>>c>>d;

    i=-1;
    while (a[++i]!='\0')a[i]=decode[a[i]];
    i=-1;
    while(a[++i]!='\0')if(a[i]<='z'&&a[i]>='a')break;
    a[i]-=32;

    i=-1;
    while (b[++i]!='\0')b[i]=decode[b[i]];
    i=-1;
    while(b[++i]!='\0')if(b[i]<='z'&&b[i]>='a')break;
    b[i]-=32;

    i=-1;
    while (c[++i]!='\0')c[i]=decode[c[i]];
    i=-1;
    while(c[++i]!='\0')if(c[i]<='z'&&c[i]>='a')break;
    c[i]-=32;

    i=-1;
    while (d[++i]!='\0')d[i]=decode[d[i]];

    cout<<a<<" "<<b<<" "<<c<<" "<<d<<endl;
    return 0;
}
