//
// Created by gatsby on 2019-02-11.
//

#ifndef LIST_LIST_H
#define LIST_LIST_H

#pragma once
#include "listNode.h"

template<typename T> class List{
private:
    int _size; ListNodePosi(T) header; ListNodePosi(T) trailer;             // 规模、头哨兵、尾哨兵

protected:
    void init();                                                            // 列表创建时的初始化
    int clear();                                                            // 清楚所有节点

};

#endif //LIST_LIST_H
