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
  key=0;
  std::queue<Member *> path;
  path->push_back(database->members[member_id]);
  color = COLOR_GRAY;
  while (path != NULL){
    Member v = path->pop_front;   //pointer on v or no?
    if (v->member_id == dst_member_id){
      v->color = COLOR_BLACK;
    }
    for (auto *it = v->connecting_members->begin(); it != v->connecting_members->end(); it++){
      if (it->dst->color == COLOR_WHITE){
        it->dst->color = COLOR_GRAY;
        path->push(it);
        key += 1;
      }
    }
  }
}

void Member::PathToMemberIDDFS(uint64_t dst_member_id) {
  // Fill in your code here
  int depth = 
  for (int i=0; i<depth; i++){
    DLS(database->members[member_id], uint64_t, depth);
  }
}
  
void Member::PrintPath(Member* dst) {
  Member *curr = dst;
  while(curr && curr != this) {
    std::cout << curr->member_name << " <- ";
    curr = curr->parent;
  }
  std::cout << this->member_name << "\n";
}

}
