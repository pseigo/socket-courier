defmodule EchoWeb.Router do
  use EchoWeb, :router

  pipeline :api do
    plug :accepts, ["json"]
  end

  scope "/api", EchoWeb do
    pipe_through :api
  end
end
