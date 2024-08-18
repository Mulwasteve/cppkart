#ifndef AISPLINECOMPONENT_HPP
#define AISPLINECOMPONENT_HPP


#include <vector>

#include<glm/glm.hpp>
#include<glm/gtc/matrix_transform.hpp>

#include "jx_engine/component/RenderComponent.hpp"
#include "jx_engine/import/PhysChunkedMapLoader.hpp"

class AISplineComponent : public EComponent {
    public:
        AISplineComponent(float scale);
        std::vector<glm::vec3> spline_verts;
         
        void getNearestVertexFromPos(glm::vec3 position, glm::vec3 &nearestVertex, glm::vec3 &nextNearestVertex);
        void tick() override;

        void Draw();

    protected:
        //* Rendering Variables & Functions 

        GLint colorUniformLOC; //Debug purposes, might move
        GLint modelMatrixLOC;
        GLint useTextureLOC;

        std::shared_ptr<Geometry> Geom;

        // Volatile GL Drawing Variables
        GLint currentCullFace;
        GLint currentFrontFace;
        
        glm::mat4 ObjmodelMatrix;
};

#endif // AISPLINECOMPONENT_HPP