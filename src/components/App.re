open StoreContext;

module Logo = {
  [@bs.module "../assets/logo.svg"] [@react.component]
  external make: (~className: string=?) => React.element = "default";
};

[@react.component]
let make = () => {
  let state = useStore();

  let className = switch state {
    | {ui: Black} => "black"
    | {ui: Color(c)} => c
  };

  <> <Logo className=className /> <h1> {React.string("Hello, world!")} </h1> </>;
};