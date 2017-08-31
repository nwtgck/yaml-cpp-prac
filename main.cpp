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
  // - Violet
  // - Dash
  // - Jack-Jack
  // given_name: Bob
  // age: ~
  // family_name: Parr

  std::cout << std::endl;

  string given_name = test1_yaml["given_name"].as<string>();
  string child1     = test1_yaml["children"][0].as<string>();

  std::cout << given_name << std::endl;
  std::cout << child1 << std::endl;

  return 0;
}
