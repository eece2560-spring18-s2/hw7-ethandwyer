#ifndef MEMBER_H_
#define MEMBER_H_

#include <vector>
#include <string>
#include <stdint.h>
#include <iostream>
#include <unordered_map>

#include "group.h"

namespace algdb {

class Member;
class Database;

#define COLOR_WHITE 0
#define COLOR_GRAY  1
#define COLOR_BLACK 2

class MemberConnection {
 public:
  Group *group;
  Member *dst;

  double GetWeight() const {
    return group->members.size() + 1;
  }
};

class Member {
  // Add extra private fields and private methods if necessary.
  Member* DLS(Member *dst, uint64_t dst_member_id, double key){
   Member *found;
   if (dst->member_id == dst_member_id){
    return dst;
  }
  
  if (key > 0){
    for (auto it = dst->connecting_members.begin(); it != dst->connecting_members.end(); it++){
      it->second.dst->parent = dst;
      found = DLS(it->second.dst, dst_member_id, key-1);
      if (found != NULL){
        return found;
      }
    }
  }
  return NULL;
}

 public:
  uint64_t member_id;
  float lat;
  float lon;
  std::string member_name;

  std::vector<uint64_t> group_ids;
  std::vector<Group *> groups;
  std::unordered_map<uint64_t, MemberConnection> connecting_members;

  void PathToMemberBFS(uint64_t dst_member_id);
  void PathToMemberIDDFS(uint64_t dst_member_id);
  void PrintPath(Member *dst);
  void DumpConnections();

  // For graph algorithms
  int color = COLOR_WHITE;
  double key; // For BST DFT, this is the depth. For MST, this is the key.
  Member *parent;
};

}

#endif
