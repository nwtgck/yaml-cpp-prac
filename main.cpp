// (from: https://www.mk-mode.com/octopress/2014/10/14/cpp-installation-yaml-cpp/)

#include <iostream>
#include <string>
#include <yaml-cpp/yaml.h>

using std::string;

int main(int argc, char* argv[]){
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

  return 0;
}
