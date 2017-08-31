// (from: https://www.mk-mode.com/octopress/2014/10/14/cpp-installation-yaml-cpp/)

#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>

using std::string;

void load_test1_yaml();
void load_test2_yaml();

int main(int argc, char* argv[]){
  if(false) {
    load_test1_yaml();
  }
  if(true){
    load_test2_yaml();
  }
  return 0;
}


void load_test1_yaml(){
  YAML::Node test1_yaml = YAML::LoadFile("test1.yaml");
  std::cout << test1_yaml << std::endl;
  // =>
  // children:
  //   - family_name: Parr
  //     children: []
  //     given_name: Violet
  //     age: ~
  //   - given_name: Dash
  //     family_name: Parr
  //     age: 10
  //     children: []
  //   - given_name: Jack-Jack
  //     age: 1
  //     children: []
  //     family_name: Parr
  // given_name: Bob
  // age: ~
  // family_name: Parr


  std::cout << std::endl;

  string given_name        = test1_yaml["given_name"].as<string>();
  string child0_given_name = test1_yaml["children"][0]["given_name"].as<string>();
  int    child2_age        = test1_yaml["children"][2]["age"].as<int>();

  std::cout << given_name << std::endl;
  std::cout << child0_given_name << std::endl;
  std::cout << child2_age << std::endl;
  // =>
  // Bob
  // Violet
  // 1
}


void load_test2_yaml(){
  YAML::Node test2_yaml = YAML::LoadFile("test2.yaml");

  // Convert YAML::Node to std::map<>
  std::map<int, string> test2_map = test2_yaml.as< std::map<int, string> >();


  // Show keys and values
  // (from: https://stackoverflow.com/a/1443798)
  for(std::map<int,string>::iterator iter = test2_map.begin(); iter != test2_map.end(); ++iter){
    std::cout << "key: " << iter->first << ", " << "value: " << iter->second << std::endl;
  }
  // =>
  // key: 1, value: apple
  // key: 2, value: orange
  // key: 3, value: melon
  // key: 4, value: grape

}