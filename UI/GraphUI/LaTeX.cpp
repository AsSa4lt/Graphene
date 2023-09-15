//
// Created by Rostyslav on 12.09.2023.
//

#include "LaTeX.hpp"

float LaTeX::GetValuePoint(float x) {
    // implement here
    return 0;
}

std::vector<sf::Vector2f> LaTeX::GetValuesFromSegment(float start, float end, float density) {
    std::vector<sf::Vector2f> result;
    // Calculate the increment for each step in x
    float increment = (end - start) / density;

    for (float currentPoint = start; currentPoint <= end; currentPoint += increment) {
        sf::Vector2f currentVector;
        currentVector.x = currentPoint;
        currentVector.y = GetValuePoint(currentVector.x);
        result.push_back(currentVector);
    }

    return result;
}

LaTeX::LaTeX() = default;
