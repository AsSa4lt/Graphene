//
// Created by Rostyslav on 12.09.2023.
//
#include "iostream"
#include "SFML/System/Vector2.hpp"
#ifndef GRAPHENE_LATEX_HPP
#define GRAPHENE_LATEX_HPP


class LaTeX {
private:
    std::string LaTexFormula;
public:
    LaTeX();
    float GetValuePoint(float x);
    std::vector<sf::Vector2f> GetValuesFromSegment(float start, float end, float density);
};


#endif //GRAPHENE_LATEX_HPP
