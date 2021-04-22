#include <iostream>
#include <string>
#include <map>
#include <iterator>

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

int main(){
  hist_t h;

  for(record r; cin >> r;){
      map<record, size_t>::iterator temp = h.find(r);
      if(temp != h.end()){
        temp -> second++;
      }
      else{
        h.insert(make_pair(r,1));
      }

  }

  cout << "{";

  for (auto &e: h){
    cout << e.first.fname_<< ' ' << e.first.lname_ << " : " << e.second << ", ";
  }

  cout << "}" << endl;
}
