// SPDX-FileCopyrightText: 2026 Xavier Leclercq
// SPDX-License-Identifier: MIT

#include "CommandLineSpecification.hpp"
#include <Ishiko/Color.hpp>
#include <Ishiko/Errors.hpp>
#include <Ishiko/Terminal.hpp>
#include <sstream>

using namespace Nuime;

int main(int argc, char* argv[])
{
    try
    {
        CommandLineSpecification command_line_spec;
        Ishiko::Configuration configuration = command_line_spec.createDefaultConfiguration();
        Ishiko::CommandLineParser::parse(command_line_spec, argc, argv, configuration);

        Ishiko::Error error;
        error.extensions().install<Ishiko::InfoErrorExtension>();

        if (error)
        {
            std::stringstream message;
            message << "ERROR: " << error << std::endl;
            Ishiko::TerminalOutput(stderr).write(message.str(), Ishiko::ColorName::red);
        }

        return error.code().value();
    }
    catch (const std::exception& e)
    {
        std::stringstream message;
        message << "EXCEPTION: " << e.what() << std::endl;
        Ishiko::TerminalOutput(stderr).write(message.str(), Ishiko::ColorName::red);

        // TODO
        return -1;
    }
    catch (...)
    {
        // TODO
        return -1;
    }
}
