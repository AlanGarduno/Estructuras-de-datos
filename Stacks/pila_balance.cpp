#include <stack>
#include <iostream>
#include <cstring>

using namespace std;

bool abre(char c)
{
	if(c == '(' || c == '[' || c == '{')
		return true;
	return false;
}

bool estaBalanceado(char desapilado, char actual)
{
	if(desapilado == '(' && actual == ')')
		return true;
	if(desapilado == '[' && actual == ']')
		return true;
	if(desapilado == '{' && actual == '}')
		return true;
	return false;
}

int main(int argc, char const *argv[])
{
	int t;
	cin>>t;
	while(t--)
	{
		stack<char> miPila;
		string str;
		cin>>str;
		int no = 0;
		for (int i = 0; i < str.length(); i++)
		{
			char actual = str[i];
			if(abre(actual))
				miPila.push(actual);
			else
			{
				char desapilado;
				if(miPila.size() > 0)
				{
					desapilado = miPila.top();
					miPila.pop();
				}
				else
				{
					no = 1;
					break;
				}
				if(estaBalanceado(desapilado,actual))
					continue;
				else
				{
					no = 1;
					break;	
				}
			}
		}
		if(miPila.size() != 0)
		{
			no = 1;
		}
		if(no)
         	cout<<"NO\n";
        else
        {
            cout<<"YES\n";
        }
	}

	return 0;
}