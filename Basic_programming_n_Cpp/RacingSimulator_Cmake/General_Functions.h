#pragma once
#include "Broom.h"
#include "Camel.h"
#include "Centaur.h"
#include "Eagle.h"
#include "FlyingCarpet.h"
#include "Header_DLL.h"

using namespace my_space;

enum class Types;
enum class Choosing_Vehicle;

void out_select_type_of_race(int& a);
std::string select_type_of_race(int& a);
void out_select_action_1(int& b);
void out_select_action_2(int& b);
void out_type_race_and_L(std::string type_race, double L);
void out_choosing_vehicle(int&);
void Continue_or_End_Game(int& a);

void select_choosing_vehicle(std::string& type_race, double& L, int& b, int& c, int& n, Ground_Race**, CamelFast&, Camel&, BootsTerrainVehicle&, Centaur&);
void print_Race_results(int, int, Ground_Race**);

void select_choosing_vehicle(std::string& type_race, double& L, int& b, int& c, int& n, Air_Race**, Broom&, Eagle&, FlyingCarpet&);
void print_Race_results(int, int, Air_Race**);

void select_choosing_vehicle(std::string& type_race, double& L, int& b, int& c, int& n, Ground_and_Air_Race**, Broom&, Eagle&, FlyingCarpet&, CamelFast& camel_fast, Camel& camel, BootsTerrainVehicle& boot_ter_veh, Centaur& cent);
void print_Race_results(int, int, Ground_and_Air_Race**);