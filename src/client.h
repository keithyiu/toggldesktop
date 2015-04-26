// Copyright 2014 Toggl Desktop developers.

#ifndef SRC_CLIENT_H_
#define SRC_CLIENT_H_

#include <string>

#include "./types.h"

#include <json/json.h>  // NOLINT

#include "Poco/Types.h"

#include "./base_model.h"

namespace toggl {

class Client : public BaseModel {
 public:
    Client()
        : BaseModel()
    , wid_(0)
    , name_("") {}

    const Poco::UInt64 &WID() const {
        return wid_;
    }
    void SetWID(const Poco::UInt64 value);

    const std::string &Name() const {
        return name_;
    }
    void SetName(const std::string value);

    std::string String() const override;

    std::string ModelName() const override {
        return "client";
    }

    std::string ModelURL() const override {
        return "/api/v8/clients";
    }

    void LoadFromJSON(Json::Value value) override;
    Json::Value SaveToJSON() const override;

    bool ResolveError(const toggl::error) override;

 private:
    Poco::UInt64 wid_;
    std::string name_;

    static bool nameHasAlreadyBeenTaken(const error err);
};

}  // namespace toggl

#endif  // SRC_CLIENT_H_
