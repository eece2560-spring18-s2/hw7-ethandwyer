#include "member.h"

#include <queue>

#include "database.h"

namespace algdb {

void Member::DumpConnections() {
  std::cout << "(" << member_id << ")";
  for (auto &m : connecting_members) {
    auto conn = m.second;
    std::cout << "->" << conn.dst->member_id << 
      "(" << conn.group->group_id << ")";
  }
  std::cout << "\n";
}

void Member::PathToMemberBFS(uint64_t dst_member_id) {
  // Fill in your code here.
  //key=0;
  std::queue<Member*> path;
  Member *curr = this;
  Member *v;
  //path.push(curr);
  curr->color = COLOR_GRAY;
  curr->key = 0;
  while (!path.empty()){
    path.pop();
  } 
  path.push(curr);
  while (!path.empty()){
    v = path.front();
    path.pop();
     for (auto it = v->connecting_members.begin(); it != v->connecting_members.end(); it++ ){
       if (it->second.dst->color == COLOR_WHITE){
          it->second.dst->color = COLOR_GRAY;
          it->second.dst->key = v->key+1;
          it->second.dst->parent = v;
          path.push(it->second.dst);
       }
     }
     v->color = COLOR_BLACK;
  }
  
}

void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
  Member *curr = this;
  for (int i=0; i<99; i++){
    DLS(curr, dst_member_id, i);
  }
  
}


  
void Member::PrintPath(Member* dst) {
  /*Member *curr = dst;
  while(curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";*/
}

}
