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

inline bool requestCompare(Request first, Request second){
    bool response;
    if(first.cost == second.cost){
        response = first.benefit < second.benefit;
    }else{
        response = first.cost < second.cost;
    }
    return response;
}

inline bool requestCompareReverse(Request first, Request second){
    bool response;
    if(first.cost == second.cost){
        response = first.benefit > second.benefit;
    }else{
        response = first.cost > second.cost;
    }
    return response;
}


#endif //TP1_MOCHILA_REQUEST_H
