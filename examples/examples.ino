#include <TinyUtilities.h>

void setup() {
    using namespace Tiny;
    char test[] = "lorem ipso factum decloratus";
    millis_t amount = Millis.Difference(0, 1);
    Memory::Segment test_segment = {test, sizeof(test)};
    Memory::Segment subset = test_segment.Offset(10, 70);

}

void loop() {

}