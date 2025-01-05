#include "Serializer.hpp"
#include "../../colors.hpp"


int main(void)
{
    Data data;
    data.id = 10;
    data.content = "content of data";

    uintptr_t raw = Serializer::serialize(&data);
    std::cout << "data&: " << YELLOW << &data << RE << std::endl;
    std::cout << "raw: " << raw << std::endl << std::endl;
    Data* deserializedData = Serializer::deserialize(raw);
    std::cout << "deserialized ptr: " << YELLOW << deserializedData << RE << std::endl;
    std::cout << "deserialized id: " << deserializedData->id << std::endl;
    std::cout << "deserialized content: " << deserializedData->content << std::endl;

    return 0;
}