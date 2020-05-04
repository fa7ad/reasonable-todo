open StoreContext;

module Logo = {
  [@bs.module "../assets/logo.svg"] [@react.component]
  external make:
    (~className: string=?, ~onClick: 'a => unit=?) => React.element =
    "default";
};

[@react.component]
let make = () => {
  let state = useStore();
  let dispatch = useDispatch();

  let color =
    switch (state) {
    | {ui: Black} => "black"
    | {ui: Color(c)} => c
    };

  let onClick = _e => {
    let action =
      switch (state.ui) {
      | Black => GoColor("red")
      | Color("red") => GoColor("blue")
      | Color("blue") => GoColor("green")
      | Color(_c) => GoBlack
      };
    dispatch(action);
  };

  <div>
    <Logo onClick className=color />
    <h1> {React.string("Hello, world!")} </h1>
  </div>;
};