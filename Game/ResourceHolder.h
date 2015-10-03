// A template class for handling resources
// By using this class and the std::unique_ptr, the class will now automatically take care of resource management - when the destructor gets called, the unique_ptr will in turn be destroyed and will automatically free the memory used for the resource 
// Note that this template will not work for the sf::Music resource which has an openFromFile function rather than a loadFromFile function since it does not load the whole resource in one step but rather small sections at a time

#ifndef RESOURCE_HOLDER
#define RESOURCE_HOLDER

#include <iostream> // For testing purposes

using std::string;
using std::runtime_error;
using std::logic_error;
using std::move;
#include<map>
using std::map;
using std::make_pair;
#include <memory>
using std::unique_ptr;
using std::make_unique;

/**
* ResourceHolder templated class - manages the loading of resources such as Textures.
* This class can be used to manage sf::Textures, sf::Sounds, sf::Shaders, etc. However it cannot handle sf::Music since that does not work the same way as the previously mentioned resources in SFML - it does not use the loadFromFile() function. 
*/
template <typename Resource, typename Identifier>
class ResourceHolder
{
public:
	/**
    * Loads the Resource from storage. 
    * @param id is the key which will be used to lookup the Resource at a later stage.
	* @param file_path_and_name is a string containing the the file path and the name of the resource to load.
    */
	void load(Identifier id, const string& file_path_and_name);	
	/**
    * Loads the Resource from storage. Overloaded to deal with two special cases - the case where the Resource is an sf::Shader and the shader type must be specified and the case where we don't want to use the default second argument of the sf::Texture version of the load function to specify a portion of the texture to load
    * @param id is the key which will be used to lookup the Resource at a later stage.
	* @param file_path_and_name is a string containing the the file path and the name of the Resource to load.
	* @param second_parameter is templated so that it can act in either of the special cases mentioned above.
    */
	template<typename Parameter>
	void load(Identifier id, const string& file_path_and_name, const Parameter& second_parameter);
	/**
    * Retrieves a Resource from the ResourceHolder based on an ID. 
    * @param id is the identifier which is used to find and then return the appropriate Resource.
	* @return is a reference to the Resource matching the id supplied.
    */	
	Resource& get(Identifier id); 
	/**
    * Retrieves a const Resource from the ResourceHolder based on an ID. 
    * @param id is the identifier which is used to find and then return the appropriate Resource.
	* @return is a constant reference to the Resource matching the id supplied.
    */	
	const Resource& get(Identifier id) const;
	
private:	
	/**
    * Adds a unique_ptr to a resource to the map of resources
    * @param id is the identifier which is used to find and then return the appropriate Resource.
	* @param is a constant reference to the Resource matching the id supplied.
    */	
	void addResource(Identifier id, unique_ptr<Resource>& resource_ptr);
	
	map<Identifier, unique_ptr<Resource>> _resources;
	
};

// Because this is a templated class, the definitions need to be included in the header file, else there will be linker errors
#include "ResourceHolder.tpp"

#endif