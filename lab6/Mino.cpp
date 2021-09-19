#include "Mino.h"

Mino::Mino(int mri): max_ri(mri){};

Mino& Mino::turn()
{
    rotate_index = (rotate_index >= max_ri)? 0:rotate_index + 1;
    return *this;
}