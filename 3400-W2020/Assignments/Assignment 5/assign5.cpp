#include <iostream>
#include <string>
#include <map>
#include <iterator>
#include <set>
#include <vector>
#include <algorithm>

using namespace std;

struct record
{
  string fname_; // first name
  string lname_; // last name
};

istream& operator >>(istream& is, record& r)
{
  is >> r.fname_ >> r.lname_;
  return is;
}

ostream& operator <<(ostream& os, record const& r)
{
  os << r.fname_ << ' ' << r.lname_;
  return os;
}

bool operator <(record const& a, record const& b)
{
  if(a.lname_ == b.lname_){
    return a.fname_ < b.fname_;
  }
  else{
    return a.lname_ < b.lname_;
  }
}

using hist_t = map<record, size_t>;
using invhist_t = map<size_t, set<record> >;

int main(){
  hist_t h;
  invhist_t ih;

  for(record r; cin >> r;){
      map<record, size_t>::iterator temp = h.find(r);
      if(temp != h.end()){
        temp -> second++;
      }
      else{
        h.insert(make_pair(r,1));
      }
  }

  for(auto &i : h){
    auto word = i.first;
    auto freq = i.second;
    auto iter = ih.insert(make_pair(freq,set<record>()));
    iter.first->second.insert(word);
  }

  for(auto &i: ih){
    auto key = i.first;
    auto list = i.second;

    cout << key << ": { ";

    for( auto i = list.begin(), e = list.end(); i != e ; i++)
    {
      cout << i->fname_ << " " << i->lname_;
      if( distance(i,e)!=1)
        cout << ", ";
    }
    cout << " }" << endl ;
   }
  cout << endl ;

}
