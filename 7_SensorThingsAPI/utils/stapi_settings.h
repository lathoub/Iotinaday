#pragma once

const char protocol[] = "http";
const char host[] = "stapi.aardvark.myds.me";
const uint16_t port = 80;
const char path[] = "/v1.0";

auto domain = String(host) + ":" + port + "/FROST-Server";
auto base_url = String(protocol) + "://" + domain + path;
