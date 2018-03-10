#include<iostream>
#include<string>
#include<stack>

using namespace std;
int main()
{
    stack <string> stk1;
    stack <string> stk2;
    string current,input,url;

    int test,i;
    cin>>test;
    for(i=1;i<=test;i++)
    {
        stk1.push("http://www.lightoj.com/");
        cout<<"Case "<<i<<":"<<endl;
        while(1)
        {
            cin>>input;
            if(input=="QUIT")
            {
                break;
            }
            else if(input=="VISIT")
            {
                cin>>url;
                stk1.push(url);
                cout<<url<<endl;
                while(!stk2.empty())
                    stk2.pop();
            }
            else if(input=="BACK")
            {
                if(!stk1.empty())
                {
                    current = stk1.top();

                    stk1.pop();
                    if(!stk1.empty())
                    {
                        stk2.push(current);
                        current=stk1.top();
                        cout<<current<<endl;
                    }

                    else
                    {
                        stk1.push(current);
                        cout<<"Ignored"<<endl;
                    }

                }
            }
            else if(input=="FORWARD")
            {
                if(!stk2.empty())
                {
                    current=stk2.top();
                    stk2.pop();
                    stk1.push(current);
                    cout<<current<<endl;
                }
                else
                    cout<<"Ignored"<<endl;
            }
        }
        while(!stk2.empty())
            stk2.pop();
        while(!stk1.empty())
            stk1.pop();
    }
    return 0;
}
