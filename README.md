# glm_inverse_perspective
Compute inverse of perspective glm::mat4 matrix

Uses 26 multiplications instead of 120. No additions and a lot less temporary storage, hence less memory accesses, resulting in better performance.

```cpp
#pragma once

#include <glm/glm.hpp>

glm::mat4 inverse_perspective(const glm::mat4& m)
{
    // Based on compute_inverse<4, 4, T, Q, Aligned> from extern/glm/glm/detail/func_matrix.inl
    // a lot of values in perspective matrices (see extern/glm/glm/ext/matrix_clip_space.inl) are zero,
    // simplify compute_inverse<4, 4, T, Q, Aligned> using all known zeros:
    auto Coef00 = 0 - m[3][2] * m[2][3];
    auto Coef07 = m[1][1] * m[2][3];

    auto Coef10 = m[1][1] * m[3][2];
    auto Coef11 = m[1][1] * m[2][2];

    glm::mat4 Inverse(
        +Coef00*m[1][1],0,0,0,
        0,+m[0][0]*Coef00,0,0,
        0,0,0,-m[0][0]*Coef07,
        0,0,-m[0][0]*Coef10,m[0][0]*Coef11
    );
    auto Determinant = (m[0][0] * Inverse[0][0]);
    auto OneOverDeterminant = static_cast<float>(1) / Determinant;
    return Inverse * OneOverDeterminant;
}
```
