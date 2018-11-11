#include <iostream>
#include <pistache/endpoint.h>

struct UYPHandler : public Pistache::Http::Handler {
    HTTP_PROTOTYPE(UYPHandler)

    void onRequest(const Pistache::Http::Request& request, Pistache::Http::ResponseWriter writer) override {
        std::cout << request.resource().c_str() + 1 << std::endl;
        Pistache::Http::serveFile(writer, request.resource().c_str() + 1);
    }
};

int main() {
    Pistache::Http::listenAndServe<UYPHandler>("*:9080");
    return 0;
}