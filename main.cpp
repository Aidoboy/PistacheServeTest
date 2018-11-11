#include <iostream>
#include <pistache/endpoint.h>

struct UYPHandler : public Pistache::Http::Handler {
    HTTP_PROTOTYPE(UYPHandler)

    void onRequest(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter writer) override {
        char* copy = strdup(request.resource().c_str() + 1);
        Pistache::Http::serveFile(writer, copy).then([copy](ssize_t bytes) {
            free(copy);
        }, Pistache::Async::NoExcept);
    }
};

int main() {
    Pistache::Http::listenAndServe<UYPHandler>("*:9080");
    return 0;
}