//
// Created by Raghuvansh Agarwal on 29/10/25.
//

#ifndef SNAKE_GAME_NODE_H
#define SNAKE_GAME_NODE_H
#include "BodyPart.h"

namespace Player {
    struct Node {
        BodyPart body_part;
        Node* next = nullptr;
    };
}
#endif //SNAKE_GAME_NODE_H