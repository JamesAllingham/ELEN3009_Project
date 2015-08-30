template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const string& file_path_and_name)
{
	auto resource_ptr = make_unique<Resource>(Resource{});
	if(!(resource_ptr->loadFromFile(file_path_and_name)))	
	{
		// A runtime error is thrown because not loading the correct resources will make the game unplayable - a try-catch block should catch runtime errors and alert the user
		throw runtime_error("ResourceHolder::load - Failed to load: " + file_path_and_name);
	}
	
	addResource(id, resource_ptr);
}

template <typename Resource, typename Identifier>
template <typename Parameter>
void ResourceHolder<Resource, Identifier>::load(Identifier id, const string& file_path_and_name, const Parameter& second_parameter)
{
	auto resource_ptr = make_unique<Resource>(Resource{});
	if(!(resource_ptr->loadFromFile(file_path_and_name, second_parameter)))
	{		
		throw runtime_error("ResourceHolder::load - Failed to load: " + file_path_and_name);
	}
	
	addResource(id, resource_ptr);
}

template <typename Resource, typename Identifier>
Resource& ResourceHolder<Resource, Identifier>::get(Identifier id)
{
	auto found_ptr = _resources.find(id);	
	assert(found_ptr != _resources.end());
	
	return *found_ptr->second;
}

template <typename Resource, typename Identifier>
const Resource& ResourceHolder<Resource, Identifier>::get(Identifier id) const
{
	auto found_ptr = _resources.find(id);	
	assert(found_ptr != _resources.end());
	
	return *found_ptr->second;
}

template <typename Resource, typename Identifier>
void ResourceHolder<Resource, Identifier>::addResource(Identifier id, unique_ptr<Resource>& resource_ptr)
{	
	auto inserted = _resources.insert(make_pair(id, move(resource_ptr)));
	// An assertion is used for debugging purposes only it will be removed by using #define NDEBUG. This should always pass and any causes for this not passing must be found during development
	assert(inserted.second);
}