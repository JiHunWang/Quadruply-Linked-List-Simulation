//
//  linked_list.h
//  project
//
//  Created by 왕지훈 on 2019. 12. 2..
//  Copyright © 2019년 Swift. All rights reserved.
//

#ifndef linked_list_h
#define linked_list_h

typedef struct Node {
    char c;
    struct Node* left;
    struct Node* right;
    struct Node* above;
    struct Node* below;
} Node;


#endif /* linked_list_h */
