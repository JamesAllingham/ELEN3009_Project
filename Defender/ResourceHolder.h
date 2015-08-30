// A template class for handling resources
// By using this class and the std::unique_ptr, the class will now automatically take care of resource management - when the destructor gets called, the unique_ptr will in turn be destroyed and will automatically free the memory used for the resource 
// Note that this template will not work for the sf::Music resource which has an openFromFile function rather than a loadFromFile function since it does not load the whole resource in one step but rather small sections at a time

#ifndef RESOURCE_HOLDER
#define RESOURCE_HOLDER

#include <assert.h>

using std::map;
using std::string;
using std::runtime_error;
using std::make_pair;
using std::move;
using std::unique_ptr;
using std::make_unique;

template <typename Resource, typename Identifier>
class ResourceHolder
{
	public:
		void load(Identifier id, const string& file_path_and_name);
		
		// A templated overload of the load method must be supplied to deal with two special cases - the case where the Reasource is an sf::Shader and the shader type must be specified and the case where we don't want to use the default second argument of the sf::Texture version of the load function to specify a portion of the texture to load
		template<typename Parameter>
		void load(Identifier id, const string& file_path_and_name, const Parameter& second_parameter);
		
		
		Resource& get(Identifier id); //maybe add const here but then the function calls might look the same?
		const Resource& get(Identifier id) const;
		
	private:		
		map<Identifier, unique_ptr<Resource>> _resources;
		
		void addResource(Identifier, unique_ptr<Resource>&);
};

// Because this is a templated class, the definitions need to be included in the header file, else there will be linker errors
#include "ResourceHolder.tpp"

#endif