open StoreContext;

module Logo = {
  [@bs.module "../assets/logo.svg"] [@react.component]
  external make: (~className: string=?) => React.element = "default";
};

[@react.component]
let make = () => {
  let state = useStore();
  let dispatch = useDispatch();

  let className =
    switch (state) {
    | {ui: Black} => "black"
    | {ui: Color(c)} => c
    };

  let onClick = _e => {
    let action =
      switch (state.ui) {
      | Black => GoColor("red")
      | Color(_c) => GoBlack
      };
    dispatch(action);
  };

  <div onClick>
    <Logo className />
    <h1> {React.string("Hello, world!")} </h1>
  </div>;
};