#include "dist/json/json.h"
#include "dist/json/json-forwards.h"
#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include "vector.h"
#include "scene_object.h"
#include "sphere.h"
#include "material.h"

using namespace std;


/*
 * json_to_vector3
 * json_to_material
 * json_to_sphere
 */


vector3_t json_to_vector3(Json::Value json_vector) {
    return vector3_t(
            json_vector["x"].asDouble(),
            json_vector["y"].asDouble(),
            json_vector["z"].asDouble());
}

color_t json_to_color(Json::Value json_color) {
    return color_t(
            json_color["r"].asDouble(),
            json_color["g"].asDouble(),
            json_color["b"].asDouble(),
            json_color["a"].asDouble()
            );
}

material_t json_to_material(Json::Value json_material) {
    return { .ambient = json_to_color(json_material["ambient"]),
        .diffuse = json_to_color(json_material["diffuse"]),
        .specular = json_to_color(json_material["specular"]),
        .emission = json_to_color(json_material["emission"]),
        .shine = json_material["shine"].asDouble()};
}

Sphere json_to_sphere(Json::Value json_sphere) {
    return Sphere(
            json_to_vector3(json_sphere["loc"]),
            json_to_material(json_sphere["material"]),
            json_sphere["radius"].asDouble());

}

void parse_file(string filename) {
    ifstream contents;
    contents.open(filename);
    Json::Value root;
    Json::Reader reader;
    bool json_parse_successful = reader.parse(contents, root);

    if (json_parse_successful) {
        cout << "Json Parsing Success" <<endl;
        Json::Value::Members json_members = root.getMemberNames();
        for (string member : json_members) {
            cout << member <<endl;
        }

        vector3_t v = json_to_vector3(root["testvector"]);
        cout << v.x << endl;

        color_t c = json_to_color(root["testcolor"]);
        cout << c.r << endl;

        material_t m = json_to_material(root["testmaterial"]);
        cout << m.shine << endl;
        int i = root["def"].asInt();
        cout << i << endl;
        Sphere s = json_to_sphere(root["testsphere"]);

    }

}




int main() 
{
    parse_file("example.json");

    return 0;
}


