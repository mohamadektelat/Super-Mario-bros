#pragma once

//---------------------------------------------------------------------------------------------------------------------

#include <SFML/Graphics.hpp>
#include <string>
#include <unordered_map>
#include <cassert>


//---------------------------------------------------------------------------------------------------------------------


/*
    Holds resources of a specific type. Make sure that these are only read into memory once so as not to
    save redundant resources.
*/
template<typename Resource, typename Identifier>
class Resource_Holder
{
public:

    /* LOAD RESOURCE TO RESOURCES HOLDER */
    void load(Identifier id, const std::string& path)
    {
        /* CREATE UNIQUE POINTER TO POINT ON NEW RESOURCE */
        std::unique_ptr<Resource> resource(std::make_unique<Resource>());   

        /* TRY TO LOAD FILE, IN CASE FAILURE: THROW EXCEPTION */
        if (!resource->loadFromFile(path))  
            throw std::runtime_error("Failed to load " + path); 

        /* MOVE RESOURCE TO CONTAINER */
        m_resources.emplace(id, std::move(resource)); 
    }

    /* LOAD RESOURCE TO RESOURCES HOLDER WITH A GIVING PARAMETER */
    template<typename Param>
    void load(Identifier id, const std::string& path, const Param& param = Param())
    {
        /* CREATE UNIQUE POINTER TO POINT ON NEW RESOURCE */
        std::unique_ptr<Resource> resource(std::make_unique<Resource>());   

        /* TRY TO LOAD FILE, IN CASE FAILURE: THROW EXCEPTION */
        if (!resource->loadFromFile(path, param))    
            throw std::runtime_error("Failed to load " + path); 

        /* MOVE RESOURCE TO CONTAINER */
        m_resources.emplace(id, std::move(resource)); //Move the resource into the container
    }


    /* GET THE RESOURCE REFERENCE BY IT'S ID */
    Resource& get(Identifier id)
    {
        return *m_resources[id];  //Find the element and reference it
    }

private:
    std::unordered_map<Identifier, std::unique_ptr<Resource>> m_resources;
};