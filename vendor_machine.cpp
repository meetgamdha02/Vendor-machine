#include <bits/stdc++.h>
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>*/

#define pll pair<long long, long long>
#define pb push_back
#define ll long long
#define ff first
#define ss second
#define D(x) cerr << #x " = " << (x) << endl
#define vll vector<ll>
#define vtt vector<int>
#define IOS                     \
  ios_base::sync_with_stdio(0); \
  cin.tie(NULL);
#define endl '\n'
using namespace std;
const int MAX = 1e5;

// meet gamdha 17BCE025


void purhaser(map<string , int>&m);
void supplier(map<string , int>&inventory){
    cout<<"You are supplier"<<endl;
    cout<<"Enter input"<<endl;
    int in;
    cin>>in;
    if(in == 1){
      inventory["Soda"] = 10;
      inventory["Coke"] = 10;
      inventory["Pepsi"] = 10;
    }
    for(auto it : inventory){
      cout<<it.first<<" "<<it.second<<endl;
    }
    cout<<"Successfully Reseted"<<endl;
    cout<<"Do you want to switch Press : 1"<<endl;
    cout<<"Do you want to Exit? Press : 2"<<endl;
    int sw;
    cin>>sw;
    if(sw == 1)purhaser(inventory);
    else if(sw == 2){
      cout<<"Have a nice Day!!"<<endl;
      exit(0);
    }
    else {
      cout<<"Invalid input"<<endl;
    }
}

void purhaser(map<string , int>&inventory){
      cout << "Enter Coin " << endl;
      int coin;
      cin>>coin;
      if(coin!=1 && coin !=5 && coin!=10 && coin!=25){
        cout<<"Invalid coins"<<endl;
        cout<<"Do you want to continue Press 1"<<endl;
        cout<<"Do you want to switch Press 2"<<endl;
        cout<<"Do You want to exit Press 3"<<endl;
        int j;
        cin>>j;
        if(j == 1)purhaser(inventory);
        else if(j == 2)supplier(inventory);
        else if(j == 3)exit(0);
      }
      cout<<"Enter number"<<endl;
      int amount;
      int number;
      cin>>number;
      amount = coin * number;
      int selected = -1;
      if (amount < 25)
      {
        cout << "Sorry You do not have enough coins to buy anything" << endl;
      }
      else if (amount >= 25 && amount < 35)
      {
        if (inventory["Coke"] == 0)
          cout << "Sorry Soda is out of stock" << endl;
        else
        {
          selected = 1;
          cout << "You have bought Coke" << endl;
          inventory["Coke"]--;
        }
      }
      else if (amount >= 35 && amount < 45)
      {
        if (inventory["Pepsi"] == 0)
          cout << "Sorry Pepsi is out of stock" << endl;
        else
        {
          selected = 2;
          cout << "You have bought Pepsi" << endl;
          inventory["Pepsi"]--;
        }
      }
      else if (amount >= 45)
      {
        if (inventory["Soda"] == 0)
          cout << "Sorry Soda is out of stock" << endl;
        else
        {
          selected = 3;
          cout << "You have bought Soda" << endl;
          inventory["Soda"]--;
        }
      }

      for(auto it : inventory){
        cout<<it.first<<" "<<it.second<<endl;
      }
      int sw;
      cout << "Do you want to switch Press : 1" << endl;
      cout<<"Do You want to continue Press  : 2"<<endl;
      cout<<"Do You Want Refund Press : 3"<<endl;
      cout<<"Dou You want to exit Press : 4"<<endl;
      cin >> sw;
      if (sw == 1)supplier(inventory);
      else if(sw == 2)purhaser(inventory);
      else if(sw == 3){
        if(selected == 1){
          inventory["Coke"]++;
          cout<<"We have returned your "<<amount<<endl;
        }
        else if(selected == 2){
          inventory["Pepsi"]++;
          cout<<"We have returned your "<<amount<<endl;
        }
        else if(selected == 1){
          inventory["Soda"]++;
          cout<<"We have returned your "<<amount<<endl;
        }
        else if(selected == -1){
          cout<<"Sorry you haven't buy any product"<<endl;
        }
        for(auto it : inventory)cout<<it.first<<" "<<it.second<<endl;
        cout<<"Do You want to continue Press :1"<<endl;
        cout<<"Do You want to switch PRess : 2"<<endl;
        cout<<"Do You want to exit PRess : 3"<<endl;
        int m;
        cin>>m;
        if(m == 1)purhaser(inventory);
        else if(m == 2)supplier(inventory);
        else if(m == 3)exit(0);
      }
      else if(sw == 4){
        cout<<"Have a nice day!!"<<endl;
        exit(0);
      }
}
int main()
{
  cout << "Are You a purchaser ?  Press : 1 " << endl;
  cout << "Are You a seller Press  : 2" << endl;
  map<string, int> inventory;
  inventory.insert({"Soda", 10});
  inventory.insert({"Coke", 10});
  inventory.insert({"Pepsi", 10});
  int in;
  cin>>in;
  if(in == 1){
    purhaser(inventory);
  }
  else{
    supplier(inventory);
  }
}