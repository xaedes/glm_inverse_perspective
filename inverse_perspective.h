#pragma once

#include <glm/glm.hpp>

glm::mat4 inverse_perspective(const glm::mat4& m)
{
    // generic perspective projection matrix of form [
    //  a,0,0,0,
    //  0,b,0,0,
    //  0,0,c,d,
    //  0,0,e,0
    // ]
    // 
    // symbolic inverse is [
    //  1/a,0,0,0,
    //  0,1/b,0,0,
    //  0,0,0,1/e,
    //  0,0,1/d,-c/(d*e)
    // ]

    auto a = m[0][0];
    auto b = m[1][1];
    auto c = m[2][2];
    auto d = m[2][3];
    auto e = m[3][2];
    glm::mat4 inv = glm::mat4(0);
    inv[0][0] = 1/a;
    inv[1][1] = 1/b;
    inv[2][3] = 1/e;
    inv[3][2] = 1/d;
    inv[3][3] = -c/(d*e);
    return inv;
}
