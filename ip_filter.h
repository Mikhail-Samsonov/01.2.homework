#pragma once

using ipAddress = std::vector<int>;

ipAddress split(const std::string&, char);

std::ostream& operator<<(std::ostream&, const ipAddress&);