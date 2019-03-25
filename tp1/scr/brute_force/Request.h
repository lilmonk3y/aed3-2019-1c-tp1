//
// Created by Christian nahuel Rivera on 23/3/19.
//

#ifndef TP1_MOCHILA_REQUEST_H
#define TP1_MOCHILA_REQUEST_H


class Request {
public:
    int cost;
    int benefit;
    Request(int cost, int benfit){
        this->cost = cost;
        this->benefit = benfit;
    }
};



#endif //TP1_MOCHILA_REQUEST_H
