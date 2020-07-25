# This file is responsible for configuring your application
# and its dependencies with the aid of the Mix.Config module.
#
# This configuration file is loaded before any dependency and
# is restricted to this project.

# General application configuration
use Mix.Config

# Configures the endpoint
config :echo, EchoWeb.Endpoint,
  url: [host: "localhost"],
  secret_key_base: "5qQpwlWBBsFllT739kySrhyPt7oX1wVClRPC6r+kSx5R92wjL2qg/2KXg543bHnw",
  render_errors: [view: EchoWeb.ErrorView, accepts: ~w(json), layout: false],
  pubsub_server: Echo.PubSub,
  live_view: [signing_salt: "WrpBjN4L"]

# Configures Elixir's Logger
config :logger, :console,
  format: "$time $metadata[$level] $message\n",
  metadata: [:request_id]

# Use Jason for JSON parsing in Phoenix
config :phoenix, :json_library, Jason

# Import environment specific config. This must remain at the bottom
# of this file so it overrides the configuration defined above.
import_config "#{Mix.env()}.exs"
